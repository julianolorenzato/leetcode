// https://leetcode.com/problems/jewels-and-stones
int numJewelsInStones(char * jewels, char * stones){
    int smallLetters[26] = {0};
    int capitalLetters[26] = {0};

    for (int i = 0; stones[i] != '\0'; i++) {
        if (stones[i] > 90) {
            smallLetters[stones[i] - 97]++;
        } else {
            capitalLetters[stones[i] - 65]++;
        }
    }

    int count = 0;

    for (int i = 0; jewels[i] != '\0'; i++) {
        if (jewels[i] > 90) {
            count += smallLetters[jewels[i] - 97];
        } else {
            count += capitalLetters[jewels[i] - 65];
        }
    }

    return count;
}