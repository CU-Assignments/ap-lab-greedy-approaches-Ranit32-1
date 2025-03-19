class Solution {
    public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            
            sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
                return a[1] > b[1]; 
            });
    
            int totalUnits = 0;
            
            for (auto& box : boxTypes) {
                int boxes = box[0], units = box[1];
                
                if (truckSize == 0) break; 
                
                int takeBoxes = min(boxes, truckSize); 
                totalUnits += takeBoxes * units;
                truckSize -= takeBoxes;
            }
            
            return totalUnits;
        }
    };
    