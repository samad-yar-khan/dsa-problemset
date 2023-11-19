#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/bus-routes/
class graph{

    private:
    int max_stops;
    vector<vector<int>>routes;
    vector<vector<int>>bus_stop_routes;

    void fill_bus_stop_routes_map(){
        this->max_stops = 1000001;
        this->bus_stop_routes = vector<vector<int>>(max_stops,vector<int>(0));
        int num_routes = routes.size();
        for(int i=0;i<num_routes;i++){
            int route_size = routes[i].size();
            for(int j =0;j<route_size;j++){
                bus_stop_routes[routes[i][j]].push_back(i);
            }
        }
    }

    public:

    graph(vector<vector<int>>routes){
        this->routes = routes;
        this->fill_bus_stop_routes_map();
    }
    bool is_valid_stop(int stop){
        return stop < this->max_stops;
    }

    bool is_valid_route(int route_index){
        return route_index < this->routes.size();
    }


    vector<int> get_route_indexes_for_stop(int stop){
        if(!is_valid_stop(stop)){
            return vector<int>();
        }
        return this->bus_stop_routes[stop];
    }

    bool is_bus_stop_in_route(int stop, int route_index){
        if(!is_valid_stop(stop)){
            return false;
        }
        for(int i =0;i<this->routes[route_index].size();i++){
            if(stop == this->routes[route_index][i]){
                return true;
            }
        }
        return false;
    }

    int num_buses_to_destination(int source, int target){
        
        //pair of bus changes and route_index
        queue<pair<int,int>>pending_nodes;
        vector<bool> queued_routes(this->routes.size(), false);
         
        vector<int> initial_routes = get_route_indexes_for_stop(source);
        for(int i =0;i<initial_routes.size();i++){
            pending_nodes.push({0,initial_routes[i]});
            queued_routes[initial_routes[i]] = true;
        }


        while(pending_nodes.size()){
            pair<int,int> node = pending_nodes.front();

            int busses_switched = node.first;
            int curr_route_index = node.second;

            pending_nodes.pop();
            if(is_bus_stop_in_route(target,curr_route_index)){
                return busses_switched;
            }

            for(int i=0;i<this->routes[curr_route_index].size();i++){
                int bus_stop = this->routes[curr_route_index][i];
                for(int j=0;j<this->bus_stop_routes[bus_stop].size();j++){
                    int route = bus_stop_routes[bus_stop][j];
                    if(queued_routes[route]){
                        continue;
                    }
                    pending_nodes.push({busses_switched+1,route});
                    queued_routes[route] = true;
                }
            }

        }
        return -1;

    }

};

int numBusesToDestinationReadable(vector<vector<int>>& routes, int source, int target) {
    graph g(routes);
    return g.num_buses_to_destination(source, target);    
}

// doing all in single func

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if(source == target){
        return 0;
    }
    unordered_map<int,vector<int>>bus_to_routes;
    for(int i =0;i<routes.size();i++){
        for(int j =0;j<routes[i].size();j++){
            bus_to_routes[routes[i][j]].push_back(i);
        }
    }

        queue<pair<int,int>>pending_nodes;
        vector<bool> queued_routes(routes.size(), false);
         
        for(int i =0;i<bus_to_routes[source].size();i++){
            pending_nodes.push({1,bus_to_routes[source][i]});
            queued_routes[bus_to_routes[source][i]] = true;
        }


        while(pending_nodes.size()){
            pair<int,int> node = pending_nodes.front();

            int busses_switched = node.first;
            int curr_route_index = node.second;

            pending_nodes.pop();

            for(int i=0;i<routes[curr_route_index].size();i++){
                int bus_stop = routes[curr_route_index][i];
                if (bus_stop == target){
                    return busses_switched;
                }
                for(int j=0;j<bus_to_routes[bus_stop].size();j++){
                    int route = bus_to_routes[bus_stop][j];
                    if(queued_routes[route]){
                        continue;
                    }
                    pending_nodes.push({busses_switched+1,route});
                    queued_routes[route] = true;
                }
            }

        }
        return -1; 
}

//more optimized

int numBusesToDestination2(vector<vector<int>>& routes, int source, int target) {
    if(source == target){
        return 0;
    }
    unordered_map<int,vector<int>>bus_to_routes;
    for(int i =0;i<routes.size();i++){
        for(int j =0;j<routes[i].size();j++){
            bus_to_routes[routes[i][j]].push_back(i);
        }
    }

        queue<pair<int,int>>pending_nodes;
        vector<bool> queued_routes(routes.size(), false);
        vector<bool> queued_nodes(routes.size(), false);
         
        for(int i =0;i<bus_to_routes[source].size();i++){
            pending_nodes.push({1,bus_to_routes[source][i]});
            queued_routes[bus_to_routes[source][i]] = true;
        }


        while(pending_nodes.size()){
            pair<int,int> node = pending_nodes.front();

            int busses_switched = node.first;
            int curr_route_index = node.second;

            pending_nodes.pop();

            for(int i=0;i<routes[curr_route_index].size();i++){
                int bus_stop = routes[curr_route_index][i];
                if (bus_stop == target){
                    return busses_switched;
                }
                for(int j=0;j<bus_to_routes[bus_stop].size();j++){
                    int route = bus_to_routes[bus_stop][j];
                    if(queued_routes[route]){
                        continue;
                    }
                    pending_nodes.push({busses_switched+1,route});
                    queued_routes[route] = true;
                }
            }

        }
        return -1; 
}

