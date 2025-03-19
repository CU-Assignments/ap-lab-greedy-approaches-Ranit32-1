class Solution {
    public:
        int minStoneSum(vector<int>& piles, int k) {
            priority_queue<int> maxHeap(piles.begin(), piles.end());
            
            while (k-- > 0) {
                int maxPile = maxHeap.top();
                maxHeap.pop();
                maxPile -= maxPile / 2; 
                maxHeap.push(maxPile);
            }
            
            int totalSum = 0;
            while (!maxHeap.empty()) {
                totalSum += maxHeap.top();
                maxHeap.pop();
            }
            
            return totalSum;
        }
    };
    