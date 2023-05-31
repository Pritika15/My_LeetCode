class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>CI; //checkin
    unordered_map<string,pair<int,int>>CO; //checkout
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        CI[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
      auto checkIN=CI[id]; // we have the values corresponding to the key=id
      CI.erase(id);
      string temp=checkIN.first+'_'+stationName;
      CO[temp].first +=t-checkIN.second;  
      CO[temp].second +=1;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
       string tempans=startStation+'_'+endStation;
       auto &ans= CO[tempans];
        return (double) ans.first/ans.second;    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */