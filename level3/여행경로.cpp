#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

vector<vector<string>> routes;
int total_tickets;
vector<vector<string>> ticket_clear;
vector<string> route_clear;

void findRoutes(vector<vector<string>> tickets, string now_location, vector<string> route){
    if(route.size() == total_tickets)
        routes.push_back(route);
    else{
        for(int i=0; i<tickets.size(); i++){
            if(now_location.compare(tickets[i][0]) == 0){
                vector<string> route_temp = route;
                vector<vector<string>> tickets_temp = tickets;

                route_temp.push_back(tickets[i][1]);
                tickets_temp.erase(tickets_temp.begin()+i);

                findRoutes(tickets_temp, tickets[i][1], route_temp);

                route_temp.swap(route_clear);
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> route;
    total_tickets = tickets.size()+1;
    route.push_back("ICN");

    findRoutes(tickets, "ICN", route);

    sort(routes.begin(), routes.end());

    return routes[0];
}
