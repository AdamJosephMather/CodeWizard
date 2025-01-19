#include "myers.h"
#include <QString>
#include <QStringList>
#include <vector>
#include <unordered_map>

Myers::Myers() {}

qfloat16 Myers::getScore(const QList<QList<int>>& path) {
	qfloat16 score = 0;
	for (int i = 1; i < path.length(); i++) {
		score += (path[i][0] == -1) ? 0.99f : (path[i][0] == 1 ? 1.01f : 0);
	}
	return score;
}

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
	
	// Custom hash for state tuples
	struct StateHash {
		std::size_t operator()(const std::tuple<int, int>& t) const {
			auto [x, y] = t;
			return std::hash<int>()(x) ^ (std::hash<int>()(y) << 1);
		}
	};
	
	// Use unordered_map instead of set for O(1) lookups
	std::unordered_map<std::tuple<int, int>, bool, StateHash> seen;
	
	// Pre-compute string equality
	std::vector<std::vector<bool>> equal(N, std::vector<bool>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			equal[i][j] = (lines1[i] == lines2[j]);
		}
	}
	
	// Dynamic programming approach
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i < N && j < M && equal[i][j]) {
				if (dp[i][j] + 1 < dp[i + 1][j + 1]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
					prev[i + 1][j + 1] = {i, j};
				}
			}
			if (i < N) {
				if (dp[i][j] + 1 < dp[i + 1][j]) {
					dp[i + 1][j] = dp[i][j] + 1;
					prev[i + 1][j] = {i, j};
				}
			}
			if (j < M) {
				if (dp[i][j] + 1 < dp[i][j + 1]) {
					dp[i][j + 1] = dp[i][j] + 1;
					prev[i][j + 1] = {i, j};
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