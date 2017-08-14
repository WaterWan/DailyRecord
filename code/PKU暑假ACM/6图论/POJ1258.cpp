#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INFINITE = 1 << 30;

struct Edge {
    int v; // �߶˵㣬��һ�˵���֪
    int w; // ��Ȩֵ��Ҳ������ʾv���ڽ���С�������ľ���
    Edge(int v_ = 0, int w_ = INFINITE) : v(v_), w(w_) {}

    bool operator<(const Edge &e) const {
        return w > e.w;
    }
};

vector <vector<Edge>> G(110); // ͼ���ڽӱ�

int HeapPrim(const vector <vector<Edge>> &G, int n) {
    // G���ڽӱ�n�Ƕ�����Ŀ������ֵ����С������Ȩֵ��
    int i, j, k;
    Edge xDist(0, 0);
    priority_queue <Edge> pq; // ��Ŷ��㼰�䵽�ڽ��������ľ���
    vector<int> vDist(n); // �����㵽�Ѿ����õ��ǲ������ľ���
    vector<int> vUsed(n); // ��Ƕ����Ƿ�Ӧ����������С������
    int nDoneNum = 0; // �Ѿ���������С�������Ķ�����Ŀ
    for (i = 0; i < n; i++) {
        vUsed[i] = 0;
        vDist[i] = INFINITE;
    }
    nDoneNum = 0;
    int nTotalW = 0; // ��С��������Ȩֵ
    pq.push(Edge(0, 0)); // ��ʼֻ�ж���0��������С����������0
    while (nDoneNum < n && !pq.empty()) {
        do { // ÿ�δӶ������������ڽ�����������ĵ�
            xDist = pq.top();
            pq.pop();
        } while (vUsed[xDist.v] == 1 && !pq.empty());
        if (vUsed[xDist.v] == 0) {
            nTotalW += xDist.w;
            vUsed[xDist.v] = 1;
            nDoneNum++;
            for (i = 0; i < G[xDist.v].size(); i++) {
                int k = G[xDist.v][i].v;
                if (vUsed[k] == 0) {
                    int w = G[xDist.v][i].w;
                    if (vDist[k] > w) {
                        vDist[k] = w;
                        pq.push(Edge(k, w));
                    }
                }
            }
        }
    }

    if (nDoneNum < n) {
        return -1; // ͼ����ͨ
    }
    return nTotalW;
}

int main() {
    int N;
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            G[i].clear();
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int w;
                cin >> w;
                G[i].push_back(Edge(j, w));
            }
        }
        cout << HeapPrim(G, N) << endl;
    }
}
