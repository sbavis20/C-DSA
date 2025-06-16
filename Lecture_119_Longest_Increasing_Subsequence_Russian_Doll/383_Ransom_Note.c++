bool canConstruct(string ransomNote, string magazine) {
    int n1 = ransomNote.size();
    int n2 = magazine.size();

    for (int i = 0; i < n1; i++) {
        bool found = false;
        for (int j = 0; j < n2; j++) {
            if (ransomNote[i] == magazine[j]) {
                magazine[j] = '-';  // mark as used
                found = true;
                break;
            }
        }
        if (!found) {
            return false;  // ransomNote[i] not found in magazine
        }
    }

    return true;
}
