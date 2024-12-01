#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int getDistance(int x, int y);


std::pair<vector<int>, vector<int>> readNums(string filename) {
    std::ifstream infile(filename);
    vector<int> vec1{};
    vector<int> vec2{};
    string line;
    string a,b;
    while (std::getline(infile, line)){
        std::istringstream ss(line);
        while (ss >> a >> b){
            vec1.push_back(std::stoi(a));
            vec2.push_back(std::stoi(b));
        }
    }
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    return std::pair<vector<int>, vector<int>>(vec1, vec2);
}

int getDistance(int x, int y){
    return std::abs(x - y);
}

void solve1(string path)
{
    auto vecs = readNums(path);
    vector<int> fuckyou{};
    for (int i = 0; i < vecs.first.size(); i++){
        fuckyou.push_back(getDistance(vecs.first[i], vecs.second[i]));
    }
    cout << std::accumulate(fuckyou.begin(), fuckyou.end(), 0);
}

void solve2(string path)
{
    auto vecs = readNums(path);
    std::set<int> setty_spaghetti{};
    std::unordered_map<int, int> mappy_pappy{};
    int64_t summy_wummy{};
    for (int i : vecs.first){
        setty_spaghetti.emplace(i);
    }
    for (int i : vecs.second){
        mappy_pappy[i]++; // Will this explode?
    }
    for(int i : setty_spaghetti)
    {
        summy_wummy += i * mappy_pappy[i];
    }
    cout << summy_wummy << "!" << '\n';
}
int main(int argc, char** argv){
    if (argc < 2)
        {
        std::cout << "forgot something, dipshit?" << std::endl;
        return 1;
    }
    //solve1(argv[1]);
    solve2(argv[1]);
    return 0;
}
