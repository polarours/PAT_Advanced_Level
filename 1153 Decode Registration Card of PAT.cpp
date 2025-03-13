#include<bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::cin.ignore();
    //id level site date order grade
    std::vector<std::tuple<std::string, std::string, std::string, std::string, std::string, int>> stu;
    std::map<std::string, std::vector<std::pair<std::string, int>>> map_level_to_stu;
    std::map<std::string, std::vector<int>> map_site_to_grage;
    std::map<std::string, std::vector<std::string>> map_date_to_site;
    std::string id, level, site, date, order;
    int grade;
        
    for(int i = 0; i < N; i++){
        std::cin >> id >> grade;
        level = id.substr(0, 1);
        site = id.substr(1, 3);
        date = id.substr(4, 6);
        order = id.substr(10, 3);
        stu.push_back({id, level, site, date, order, grade});
        map_level_to_stu[level].push_back({id, grade});
        map_site_to_grage[site].push_back(grade);
        map_date_to_site[date].push_back(site);
    }

    std::vector<std::pair<int, std::string>> query;
    std::string query_inf;
    int query_index;
    for(int i = 0; i < M; i++){
        std::cin >> query_index >> query_inf;
        query.push_back({query_index, query_inf});
    }

    int index = 1;
    for(const auto& pair : query){
        if(pair.first == 1){
            std::string level = pair.second;
            if(map_level_to_stu.find(pair.second) == map_level_to_stu.end()){
                std::cout << "Case " << index++ << ": " << pair.first << " " << pair.second << std::endl;
                std::cout<< "NA" << std::endl;
            }else{
                std::vector<std::pair<std::string, int>> vec = map_level_to_stu[pair.second];
                std::sort(vec.begin(), vec.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b){
                   if(a.second == b.second){
                       return a.first < b.first;
                   }
                    return a.second > b.second;
                });
                std::cout << "Case " << index++ << ": " << pair.first << " " << pair.second << std::endl;
                for(const auto& card : vec){
                    std::cout << card.first << " " << card.second << std::endl;
                }
            }
        }else if(pair.first == 2){
            if(map_site_to_grage.find(pair.second) == map_site_to_grage.end()){
                std::cout << "Case " << index++ << ": " << pair.first << " " << pair.second << std::endl;
                std::cout << "NA" << std::endl;    
            }
            else {
                std::vector<int> vec = map_site_to_grage[pair.second];
                int sum = 0;
                for(int num : vec) sum += num;
                std::cout << "Case " << index++ << ": " << pair.first << " " << pair.second << std::endl;
                std::cout << vec.size() << " " << sum << std::endl;
            }
        }else if(pair.first == 3){
            if(map_date_to_site.find(pair.second) == map_date_to_site.end()){
                std::cout << "Case " << index++ << ": " << pair.first << " " << pair.second << std::endl;
                std::cout << "NA" << std::endl;
            }else{
                std::vector<std::string> vec = map_date_to_site[pair.second];
                std::unordered_map<std::string, int> m;
                for(const auto& site : vec){
                    if(m.find(site) != m.end()){
                        m[site]++;
                    }else{
                        m[site] = 1;
                    }
                }
                std::vector<std::pair<std::string, int>> temp;
                for(const auto& pair : m){
                    temp.push_back({pair.first, pair.second});
                }
                std::sort(temp.begin(), temp.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b){
                      return a.second > b.second;              
                });
                std::cout << "Case " << index++ << ": " << pair.first << " " << pair.second << std::endl;
                for(const auto& pair : temp){
                    std::cout << pair.first << " " << pair.second << std::endl;
                }
            }
        }
    }
       
    return 0;
}