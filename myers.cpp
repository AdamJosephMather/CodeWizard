#include "myers.h"
#include <QString>
#include <QStringList>
#include <qdebug.h>
#include <qelapsedtimer.h>
#include <vector>

Myers::Myers() {}

/*QList<QStringList> Myers::getDiff(const QString& string1, const QString& string2) {
	QElapsedTimer timer;
	timer.start();
	
	QStringList lines1 = string1.split("\n");
	QStringList lines2 = string2.split("\n");
	
	const int lenL1 = lines1.length();
	const int lenL2 = lines2.length();
	
	std::vector<std::vector<bool>> isDone(lenL1, std::vector<bool>(lenL2, false));
	
	QList<int> runsStartX;
	QList<int> runsStartY;
	QList<int> runsEndX;
	QList<int> runsEndY;
	
	for (int x = 0; x < lenL1; x++){
		for (int y = 0; y < lenL2; y++){
			if (isDone[x][y]){
				continue;
			}
			isDone[x][y] = true;
			
			if (lines1[x] != lines2[y]){
				continue;
			}
			
			int runStartX = x;
			int runStartY = y;
			int runEndX = x;
			int runEndY = y;
			
			int t = 1;
			while (true){
				int newX = x+t;
				int newY = y+t;
				
				if (newX >= lenL1 || newY >= lenL2){
					break;
				}
				
				isDone[newX][newY] = true;
				
				if(lines1[newX] != lines2[newY]){
					break;
				}
				
				runEndX = newX;
				runEndY = newY;
				
				t ++;
			}
			
			runsStartX.push_back(runStartX);
			runsStartY.push_back(runStartY);
			runsEndX.push_back(runEndX+1);
			runsEndY.push_back(runEndY+1);
		}
	}
	
	qDebug() << "Time to get runs:" << timer.elapsed() << "Num runs:" << runsStartX.length();
	
	int sX = 0;
	int sY = 0;
	
	QVector<int> bestScores(runsStartX.length());
	QVector<bool> cacheReady(runsStartX.length());
	QVector<int> bestGotos(runsStartX.length()+1);
	
	int bestScore = recurse(-1, sX, sY, lenL1, lenL2, &cacheReady, &bestGotos, &bestScores, &runsStartX, &runsStartY, &runsEndX, &runsEndY);
	
	qDebug() << "Time to recurse: " << timer.elapsed();
	
	QList<QStringList> final;
	
	int at = -1;
	int x = 0;
	int y = 0;
	
	while (true){
		int gotoIndx = bestGotos[at+1];
		
		int movesRight = 0;
		int movesDown = 0;
		int nonMoves = 0;
		bool breakAfter = false;
		
		if (gotoIndx == -1){
			movesRight = lenL1-x;
			movesDown = lenL2-y;
			breakAfter = true;
		}else{
			int sx = runsStartX.at(gotoIndx);
			int sy = runsStartY.at(gotoIndx);
			int ex = runsEndX.at(gotoIndx);
			int ey = runsEndY.at(gotoIndx);
			
			if (sx < x){
				int d = x-sx;
				sx += d;
				sy += d;
			}
			if (sy < y){
				int d = y-sy;
				sx += d;
				sy += d;
			}
			
			nonMoves = ex-sx;
			movesRight = sx-x;
			movesDown = sy-y;
		}
		
		for (int i = 0; i < movesRight; i++){
			final.push_back(QStringList() << "-" << lines1[x]);
			x += 1;
		}
		for (int i = 0; i < movesDown; i++){
			final.push_back(QStringList() << "+" << lines2[y]);
			y += 1;
		}
		for (int i = 0; i < nonMoves; i++){
			final.push_back(QStringList() << "=" << lines1[x]);
			x += 1;
			y += 1;
		}
		
		if (breakAfter){break;}
		
		at = gotoIndx;
	}
	
	qDebug() << "Time to finalize: " << timer.elapsed();
	
	return final;
}

int Myers::recurse(int at, int x, int y, int lenL1, int lenL2, QVector<bool>* cacheReady, QVector<int>* bestGotos, QVector<int>* bestScores, QList<int>* runsStartX, QList<int>* runsStartY, QList<int>* runsEndX, QList<int>* runsEndY){
	int bestScore = INT_MAX;
	int bestGoto = -1;
	
	for (int i = at+1; i < runsStartX->length(); i++){
		int newX = runsEndX->at(i);
		int newY = runsEndY->at(i);
		
		if (newX <= x || newY <= y){
			continue;
		}
		
		int scr;
		if (cacheReady->at(i)){
			scr = bestScores->at(i);
		}else{
			scr = recurse(i, newX, newY, lenL1, lenL2, cacheReady, bestGotos, bestScores, runsStartX, runsStartY, runsEndX, runsEndY);
			(*cacheReady)[i] = true;
			(*bestScores)[i] = scr;
		}
		
		int sx = runsStartX->at(i);
		int sy = runsStartY->at(i);
		
		if (sx < x){
			int d = x-sx;
			sx += d;
			sy += d;
		}
		if (sy < y){
			int d = y-sy;
			sx += d;
			sy += d;
		}
		
		int score = (sx-x) + (sy-y) + scr;
		
		if (score < bestScore){
			bestScore = score;
			bestGoto = i;
		}
	}
	
	int score = (lenL1-x) + (lenL2-y);
	
	if (score < bestScore){
		bestScore = score;
		bestGoto = -1;
	}
	
	(*bestGotos)[at+1] = bestGoto;
	
	return bestScore;
}*/

QList<QStringList> Myers::getDiff(const QString& string1, const QString& string2) {
	QStringList lines1 = string1.split("\n");
	QStringList lines2 = string2.split("\n");
	
	const int N = lines1.length();
	const int M = lines2.length();
	
	// Use vector instead of QList for better performance
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, INT_MAX));
	std::vector<std::vector<std::pair<int, int>>> prev(N + 1, std::vector<std::pair<int, int>>(M + 1));
	
	// Initialize base cases
	dp[0][0] = 0;
		
	// Pre-compute string equality
	std::vector<std::vector<bool>> equal(N, std::vector<bool>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			equal[i][j] = (lines1[i] == lines2[j]);
		}
	}
	
	// Dynamic programming approach
	
	for (int j = 0; j <= M; j++) {
		for (int i = 0; i <= N; i++) {
			if (i < N && j < M && equal[i][j]) {
				if (dp[i][j] + 1 < dp[i + 1][j + 1]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
					prev[i + 1][j + 1] = {i, j};
				}
			}
			if (j < M) {
				if (dp[i][j] + 1 < dp[i][j + 1]) {
					dp[i][j + 1] = dp[i][j] + 1;
					prev[i][j + 1] = {i, j};
				}
			}
			if (i < N) {
				if (dp[i][j] + 1 < dp[i + 1][j]) {
					dp[i + 1][j] = dp[i][j] + 1;
					prev[i + 1][j] = {i, j};
				}
			}
		}
	}
	
	// Reconstruct the path
	QList<QStringList> finalChanges;
	int i = N, j = M;
	
	while (i > 0 || j > 0) {
		QStringList changeEntry;
		auto [pi, pj] = prev[i][j];
		
		if (pi < i && pj < j) {
			changeEntry << "=" << lines1[pi];
		} else if (pi < i) {
			changeEntry << "-" << lines1[pi];
		} else {
			changeEntry << "+" << lines2[pj];
		}
		
		finalChanges.prepend(changeEntry);
		i = pi;
		j = pj;
	}
	
	return finalChanges;
}