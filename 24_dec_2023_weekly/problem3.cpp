class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int num_nodes = 26;
        vector<vector<long long>> distances(num_nodes, vector<long long>(num_nodes, LLONG_MAX));

        for (int i = 0; i < num_nodes; ++i) {
            distances[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int src_node = original[i] - 'a';
            int dst_node = changed[i] - 'a';
            int weight = cost[i];

            distances[src_node][dst_node] = min(distances[src_node][dst_node], (long long)(weight));
        }

        for (int k = 0; k < num_nodes; ++k) {
            for (int i = 0; i < num_nodes; ++i) {
                for (int j = 0; j < num_nodes; ++j) {
                    if (distances[i][k] != LLONG_MAX && distances[k][j] != LLONG_MAX) {
                        if (distances[i][k] + distances[k][j] < distances[i][j]) {
                            distances[i][j] = distances[i][k] + distances[k][j];
                        }
                    }
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < source.size(); ++i) {
            int src_char = source[i] - 'a';
            int dest_char = target[i] - 'a';
            if (src_char == dest_char) {
                continue;
            }
            if (distances[src_char][dest_char] == LLONG_MAX) {
                return -1;
            } else {
                result += distances[src_char][dest_char];
            }
        }

        return result;
    }
};

