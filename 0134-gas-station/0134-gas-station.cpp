class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int totalGas=0,totalCost=0;
        for(int i=0;i<gas.size();i++)
        {
            totalGas=totalGas+gas[i];
        }
        for(int i=0;i<cost.size();i++)
        {
            totalCost=totalCost+cost[i];
        }
        if(totalGas< totalCost) return -1;
        int fuel=0;
        for(int i=0;i<gas.size();i++)
        {
           fuel+=gas[i]-cost[i];
            if(fuel<0)
            {
                start=i+1;
                fuel=0;
            }
                
        }
        return start;
    }
};