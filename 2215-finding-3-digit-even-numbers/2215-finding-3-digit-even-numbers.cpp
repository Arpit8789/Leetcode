class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++; // count of each digit
        //freq[2] = 3
//freq[8] = 2

        vector<int> result;

        for (int num = 100; num <= 999; num += 2) { // check only even 3-digit numbers
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            // count digits needed for this number
            vector<int> count(10, 0);
           // count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
// index 0 means count of digit '0', index 1 means count of digit '1', ..., index 9 is for digit '9' eg:228

            count[a]++;
            count[b]++;
            count[c]++;

            bool canForm = true;
            for (int d = 0; d < 10; ++d) {
                if (count[d] > freq[d]) {
                    canForm = false;
                    break;
                }
            }
            //count = [0, 0, 2, 0, 0, 0, 0, 0, 1, 0]
// meaning: 2 twos and 1 eight needed to form the number 228


            if (canForm) {
                result.push_back(num);
            }
        }

        return result;
    }
};
