vector<pair<int,int>> events;

for(auto &it : intervals){
    events.push_back({it[0], +1}); // start
    events.push_back({it[1], -1}); // end
}

sort(events.begin(), events.end());

int active=0;

for(auto &e : events){
    active += e.second;
}