# 🪜 Word Ladder BFS Solution

---

## 🔄 Logical Steps (Start → Finish)

### 1. Make fast lookup set
- `wordList` ko `unordered_set (dict)` me daal do → O(1) lookup ke liye.  

### 2. Early exit
- Agar `endWord` dict me hi nahi hai → koi path possible nahi → return `0`.  

### 3. Initialize BFS
- Queue me `(beginWord, 1)` push karo.  
- `1` ka matlab: abhi sequence length sirf `beginWord` tak hai.  

### 4. BFS loop start
- Jab tak queue non-empty hai:
  - Front nikaalo `(word, steps)`.  

### 5. Goal check (early success)
- Agar `word == endWord` → shortest path mil gaya (BFS guarantee) → return `steps`.  

### 6. Generate all neighbors (1-letter change)
- Har index `i` ke liye:
  - Ek `temp` copy banao.  
  - `'a'` se `'z'` tak har character try karo.  
  - (Optimization: agar `c == original char` ho to skip).  
  - `temp[i] = c` se naya candidate banta hai.  

### 7. Validate neighbor
- Agar yeh `temp` dict me hai:
  - Valid next word hai (1 move me reachable).  
  - Queue me `(temp, steps+1)` push karo.  

### 8. Mark visited immediately
- `dict.erase(temp)` karo usi waqt → dobara visit na ho.  
- BFS ki branching control hoti hai, speed bhi badhta hai.  

### 9. Repeat until queue exhausts
- Saare neighbors process karne ke baad loop agle word pe chalta rahega.  

### 10. No path found
- Agar queue khatam ho gayi aur `endWord` nahi mila → return `0`.  

---

## 🧠 Why Yeh Approach Sahi Hai?

- **BFS kyon?**  
  Shortest number of steps chahiye. Har step ka weight 1 hai. BFS level-by-level expand karta hai → pehli baar `endWord` milega to woh shortest hoga.  

- **On-the-fly neighbors kyon?**  
  Poora graph banane me `O(N^2 * L)` lagega. Yaha hum dynamically neighbors banate hain (`O(L*26)`), faster hai.  

- **Set/erase kyon?**  
  Fast membership check. `erase` se ek word ek hi baar visit hota hai → cycles/duplication avoid.  

- **Steps store kyon?**  
  Queue ke saath `steps` rakhne se exact sequence length track hota hai.  

---

## 🔍 Micro Walkthrough (1 Round)

Queue:  

Steps:  
1. Pop → "hit", steps=1.  
2. Neighbors: `"ait","bit",...,"hot",..."zit"`.  
3. Sirf `"hot"` dict me hai → push `("hot", 2)`.  
4. Dict se `"hot"` erase.  
5. Next loop me `"hot"` se `"dot","lot"` milenge → steps=3, and so on...  

---

## ⚡ Edge Cases

- `beginWord == endWord` → steps = 1.  
- Duplicate words → dict unique + erase → problem nahi.  
- Non-connected dict → BFS khatam ho jaayega → return `0`.  

---

## ⏱️ Complexity (intuition)

- Har valid word ek hi baar queue me jaata hai.  
- Har word ke liye `L * 26` neighbors check hote hain.  
- **Time:** `O(N * L * 26)`  
- **Space:** `O(N)` (dict + queue)  

---

## 📝 TL;DR (1-line mental model)

👉 *Queue se word nikaalo → 1-letter change karke jitne valid next words milen, unhe steps+1 ke saath push karo → pehli baar `endWord` mile, wahi shortest length hai; warna 0.*  

---

## 💻 C++ BFS Code


```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // make the dictionary se to look in  O(1)

        int n=wordList.size();
        set<string>dict;
        for(int i=0; i<n; i++){
            dict.insert(wordList[i]);
        }
 
        if(dict.find(endWord)==dict.end())  return 0;

        //make queue 
        queue<pair<string, int>>q; //string,steps
        q.push({beginWord,1});
        while(!q.empty()){
            auto [word,steps]=q.front();
            q.pop();

            if(word==endWord) return steps;

            //now generte all the string with diff 1 change
            for(int i=0; i<word.size(); i++){
                string temp=word;
                for(char ch='a'; ch<='z'; ch++){
                    temp[i]=ch;
                    if(dict.find(temp)!=dict.end()){
                        q.push({temp,steps+1});
                        dict.erase(temp);
                    }
                }
            }


        }

        return 0;
    }
};


```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Step 1: Put all words from wordList into a set for quick lookup
        unordered_set<string> dict(wordList.begin(), wordList.end());

        // If endWord is not present in wordList, transformation is impossible
        if (dict.find(endWord) == dict.end()) return 0;

        // Step 2: BFS queue -> stores (word, steps)
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // Start with beginWord, step = 1

        // Step 3: BFS loop
        while (!q.empty()) {
            auto [word, steps] = q.front(); // Current word and steps taken
            q.pop();

            // If we reached the endWord, return steps
            if (word == endWord) return steps;

            // Step 4: Try changing each character of the word
            for (int i = 0; i < word.size(); i++) {
                string temp = word; // Copy the current word

                // Replace character at position i with every letter 'a' to 'z'
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c; // Change one character

                    // If this new word exists in dict, it's a valid transformation
                    if (dict.find(temp) != dict.end()) {
                        q.push({temp, steps + 1}); // Push into queue with incremented step
                        dict.erase(temp); // Remove from dict to avoid revisiting
                    }
                }
            }
        }

        // If no transformation possible
        return 0;
    }
};



