#include <bits/stdc++.h>
#define maxn 100005
#define MP make_pair
#define PB push_back
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())

using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
// shuffle(begin, end, rnd), rnd() % n

typedef long long ll;
typedef pair<int, int> PII;

int N;
unordered_map<string, int> myMap;

int common(const vector<int>& tags1, const vector<int>& tags2) {
    int i = 0, j = 0;
    int c = 0;
    while (i < tags1.size() && j < tags2.size()) {
        if (tags1[i] == tags2[j]) {
            ++c;
            ++i;
            ++j;
        } else if (tags1[i] < tags2[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    return c;
}
vector<int> merge(const vector<int>& tags1, const vector<int>& tags2) {
    int i = 0, j = 0;
    vector<int> ans;
    while (i < tags1.size() && j < tags2.size()) {
        if (tags1[i] == tags2[j]) {
            ans.PB(tags1[i]);
            ++i;
            ++j;
        } else if (tags1[i] < tags2[j]) {
            ans.PB(tags1[i]);
            ++i;
        } else {
            ans.PB(tags2[j]);
            ++j;
        }
    }
    return ans;
}

class VerticalPhoto {
public:
    int id;
    vector<int> tags;
    VerticalPhoto(int _id, const vector<int>& ts) {
        id = _id;
        tags.insert(tags.end(), ts.begin(), ts.end());
    }
};

class Slide {
public:
    vector<int> ids, tags;
    Slide(int id, const vector<int>& ts) {
        ids.push_back(id);
        tags.insert(tags.end(), ts.begin(), ts.end());
    }
    Slide(int id1, int id2, const vector<int>& ts) {
        ids.push_back(id1);
        ids.push_back(id2);
        tags.insert(tags.end(), ts.begin(), ts.end());
    }
    bool connected(const Slide& slide) {
        return common(tags, slide.tags) > 0;
    }
    bool score(const Slide& slide) {
        int c = common(tags, slide.tags);
        return min(c, min((int)tags.size() - c, (int)slide.tags.size() - c));
    }
    void print() const {
        printf ("%i:", ids[0]);
        for (int i = 0; i < tags.size(); ++i)
            printf (" %i", tags[i]);
        printf ("\n");
    }
};


vector<VerticalPhoto> photos;
vector<Slide> slides;
vector<unordered_set<int>> tagToSlides;

vector<pair<int,int>> vertical_merge(int find_number) {
    srand(0);
    int n = photos.size();

    vector<int>ids(n);
    for(int i=0;i<n;i++)ids[i]=i;

    vector<int>another(n,-1);
    vector<pair<int,int>> ans;
    if (find_number == n) {
        for (int i = 0; i < n-1; i++) {
            if (another[i] >= 0)
                continue;
            int min_c = 101, min_j = -1;
            for (int j = i+1; j < n; j++) {
                if (another[j] >= 0)
                    continue;
                int c = common(photos[i].tags,photos[j].tags);
                if (c < min_c){
                    min_c = c;
                    min_j = j;
                }
            }
            if (min_j == -1)
                break;
            another[i]=min_j;
            another[min_j]=i;
            ans.push_back(make_pair(i,min_j));
        }
    }
    else{
        for(int i=0;i<n/2;i++){
            int t = find_number;
            int min_c = 100,min_j = -1,min_idx = 0;
            while(t--){
                int idx = rand()%(ids.size()-1)+1;
                int j = ids[idx];
                int c = common(photos[i].tags,photos[j].tags);
                if(c<min_c){
                    min_c = c;
                    min_j = j;
                    min_idx = idx;
                }
            }
            if (min_j == -1)
                break;
            another[i]=min_j;
            another[min_j]=i;
            swap(ids[min_idx],ids[ids.size()-1]);
            swap(ids[i],ids[ids.size()-2]);
            ids.resize(ids.size()-2);
            ans.push_back(make_pair(i,min_j));
        }
    }
    return ans;
}

unordered_set<int> indices;

int main() {
    cin >> N;
    string h;
    int M, t;
    vector<int> tags;
    string tag;
    for (int i = 0; i < N; ++i) {
        cin >> h >> M;
        tags.clear();
        for (int j = 0; j < M; ++j) {
            cin >> tag;
            if (myMap.find(tag) == myMap.end())
                myMap[tag] = myMap.size() + 1;
            tags.push_back(myMap[tag]);
        }
        sort(tags.begin(), tags.end());
        if (h == "H") {
            slides.push_back(Slide(i, tags));
        } else {
            photos.push_back(VerticalPhoto(i, tags));
        }
    }
    vector<pair<int, int>> VPair = vertical_merge(min(1000, (int)photos.size()));
    for (int i = 0; i < VPair.size(); ++i) {
        int a = VPair[i].first;
        int b = VPair[i].second;
        slides.push_back(Slide(photos[a].id, photos[b].id, merge(photos[a].tags, photos[b].tags)));
    }

    // tagToSlides.resize(myMap.size() + 10);

    // for (int i = 0; i < slides.size(); ++i) {
    //     for (int j = 0; j < slides[i].tags.size(); ++j)

    // }

    for (int i = 0; i < slides.size(); ++i)
        indices.insert(i);

    list<int> slideshow;
    slideshow.push_back(*(indices.begin()));
    indices.erase(indices.begin());
    while (indices.empty() == false) {
        bool flag = true;
        int index = -1;
        int score = -1;
        for (auto it = indices.begin(); it != indices.end(); ++it) {
            if (slides[slideshow.back()].connected(slides[*it])) {
                int tempScore = slides[slideshow.back()].score(slides[*it]);
                if (tempScore > score) {
                    score = tempScore;
                    index = *it; 
                }
                
                flag = false;
            }
        }
        if (flag)
            break;
        slideshow.push_back(index);
        indices.erase(index);
    }
    while (indices.empty() == false) {
        bool flag = true;
        int index = -1;
        int score = -1;
        for (auto it = indices.begin(); it != indices.end(); ++it) {
            if (slides[slideshow.front()].connected(slides[*it])) {
                int tempScore = slides[slideshow.front()].score(slides[*it]);
                if (tempScore > score) {
                    score = tempScore;
                    index = *it; 
                }
                flag = false;
            }
        }
        if (flag)
            break;
        slideshow.push_front(index);
        indices.erase(index);
    }

    cout << slideshow.size() << endl;
    for (auto it = slideshow.begin(); it != slideshow.end(); ++it) {
        int index = *it;
        for (int i = 0; i < slides[index].ids.size(); ++i) {
            if (i != 0)
                printf (" ");
            printf ("%i", slides[index].ids[i]);
        }
        printf ("\n");
    }

    return 0;
}

