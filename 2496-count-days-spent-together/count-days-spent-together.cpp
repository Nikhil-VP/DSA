class Solution {
public:
    int numberofdays(string date){
        int tdays=0;
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        int mm = stoi(date.substr(0,2));
        int dd = stoi(date.substr(3,2));
        for(int i=0;i<mm-1;i++){
            tdays += days[i];
        }
        tdays += dd;
        return tdays;

    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int alice1 = numberofdays(arriveAlice);
        int alice2 = numberofdays(leaveAlice);
        int bob1 = numberofdays(arriveBob);
        int bob2 = numberofdays(leaveBob);
        int overlapStart = max(alice1, bob1);
        int overlapEnd = min(alice2, bob2);
        
        if (overlapStart > overlapEnd) {
            return 0;
        }
        
        return overlapEnd - overlapStart + 1;
    
    }
};