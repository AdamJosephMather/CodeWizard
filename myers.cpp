#include "myers.h"
#include <qcontainerfwd.h>
#include <QString>
#include <QStringList>
#include <queue>
#include <set>
#include <tuple>

Myers::Myers() {}

qfloat16 Myers::getScore(QList<QList<int>> path) {
	qfloat16 score = 0;
	
	for (int i = 1; i < path.length(); i++) {
		if (path[i][0] == -1) {  // deletion
			score += 0.99;
		} else if (path[i][0] == 1) {  // addition
			score += 1.01;
		}
	}
	
	return score;
}

QList<QStringList> Myers::getDiff(QString string1, QString string2) {
	QStringList lines1 = string1.split("\n");
	QStringList lines2 = string2.split("\n");
	
	// Priority queue using tuple of (priority, state)
	// where state is (x, y, path)
	using State = std::tuple<int, int, QList<QList<int>>>;
	using PQEntry = std::pair<qfloat16, State>;
	std::priority_queue<PQEntry, std::vector<PQEntry>, std::greater<PQEntry>> q;
	
	// Initialize queue with starting state
	q.push({0, {0, 0, QList<QList<int>>()}});
	
	int fX = lines1.length();
	int fY = lines2.length();
	QList<QList<int>> finalPath;
	
	// Using set to track seen states
	std::set<std::tuple<int, int, int>> seen;
	
	const qfloat16 speed = 1.4;  // Adjust as needed
	
	while (!q.empty()) {
		auto [priority, state] = q.top();
		q.pop();
		
		auto [x, y, path] = state;
		
		// Create state tuple for seen check
		auto seenState = std::make_tuple(path.length(), x, y);
		if (seen.find(seenState) != seen.end()) {
			continue;
		}
		seen.insert(seenState);
		
		if (x == fX && y == fY) {
			finalPath = path;
			break;
		}
		
		// Check for matching lines
		if (x < fX && y < fY) {
			if (lines1[x] == lines2[y]) {
				int nx = x + 1;
				int ny = y + 1;
				QList<QList<int>> newPath = path;
				newPath.append({2, x, y});  // 2 represents '='
				qfloat16 newPriority = getScore(newPath) * speed + (fX - nx) + (fY - ny);
				q.push({newPriority, {nx, ny, newPath}});
			}
		}
		
		// Check deletion and addition cases
		const std::vector<std::tuple<int, int, int>> operations = {
			{-1, 1, 0},  // deletion
			{1, 0, 1}    // addition
		};
		
		for (const auto& [type, ax, ay] : operations) {
			int nx = x + ax;
			int ny = y + ay;
			
			if (nx <= fX && ny <= fY) {
				QList<QList<int>> newPath = path;
				newPath.append({type, x, y});
				qfloat16 newPriority = getScore(newPath) * speed + (fX - nx) + (fY - ny);
				q.push({newPriority, {nx, ny, newPath}});
			}
		}
	}
	
	// Process final changes
	QList<QStringList> finalChanges;
	QStringList newStr = lines1;
	int loc = 0;
	
	for (const QList<int>& change : finalPath) {
		QStringList changeEntry;
		if (change[0] == 2) {  // Equal
			changeEntry << "=" << newStr[loc];
			loc++;
		} else if (change[0] == -1) {  // Deletion
			changeEntry << "-" << newStr[loc];
			newStr.removeAt(loc);
		} else if (change[0] == 1) {  // Addition
			changeEntry << "+" << lines2[change[2]];
			newStr.insert(loc, lines2[change[2]]);
			loc++;
		}
		finalChanges.append(changeEntry);
	}
	
	return finalChanges;
}