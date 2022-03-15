calss Solution
{
    int GetMatrixSum(int rows, int cols, const vector<pair<int, int>> &baseStations, const vector<Command> &cmds) {
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        vector<pair<int,int>> newBases(baseStations);
        for (auto& c : cmds) {
            if(c.cmd == "delete") {
                newBases.erase(find(newBases.begin(), newBases.end(), make_pair(c.row, c.col)));
            }
            else if(c.cmd == "add") newBases.push_back(make_pair(c.row, c.col));
        }
        int result = 0;
        for (auto& st : baseStations) {
            // left, right, up, down, left+up, left+down, right+up, right+down
            if (st.first - 1 > 0) result += 1;
            else if(st.first + 1 <= cols) result +=1;
            else if(st.second - 1 > 0) result +=1;
            else if(st.second + 1 <= rows) result += 1;
            else if(st.first - 1 > 0 && st.second - 1 > 0) result += 1;
        }
        return result;
    }
}
