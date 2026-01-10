class Solution {
public:
    string simplifyPath(string path) {
        vector<string> folders;
        string res;
        for (int i = 0; i < path.size(); i++)
        {
            string temp = "/";
            i++;
            while (i < path.size() && path[i] == '/')
            {
                i++;
            }
            while (i < path.size() && path[i] != '/')
            {
                temp.push_back(path[i]);
                i++;
            }
            if (i < path.size() && path[i] == '/')
            {
                i--;
            }
            if (temp == "/." || temp == "/")
            {

            }
            else if (temp == "/..")
            {
                if (folders.size() > 0) folders.erase(folders.end());
            }
            else
            {
                folders.push_back(temp);
            }
        }
        for (string str: folders)
        {
            res.append(str);
        }
        if (res.size() == 0) res = "/";
        return res;
    }
};
