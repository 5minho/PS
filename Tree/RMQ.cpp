//
// Created by 오민호 on 2017. 9. 6..
//


const int INF = std::numeric_limits<int>::max();

struct RMQ {

    std::vector<int> rangeMin;
    int size;

    RMQ(const std::vector<int>& array) {

        size = array.size();
        rangeMin.reserve(size * 4);
        init(array, 1, size, 1);

    }

    int init(const std::vector<int>& array, int left, int right, int node) {

        if (left == right) {
            return rangeMin[node] = array[left];
        }

        int mid = (left + right) / 2;

        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right,  node * 2 + 1);

        return rangeMin[node] = std::min(leftMin, rightMin);
    }

    int query(int left, int right, int node, int nodeLeft, int nodeRight) {

        if (right < nodeLeft || nodeRight < left) {
            return INF;
        }

        if (left <= nodeLeft && nodeRight <= right)
            return rangeMin[node];

        int mid = (nodeLeft + nodeRight) / 2;
        return std::min(query(left, right, node * 2, nodeLeft, mid),
                        query(left, right, node * 2 + 1, mid + 1, nodeRight));

    }

    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {

        if (index < nodeLeft || nodeRight < index)
            return rangeMin[node];

        if (nodeLeft == nodeRight) return rangeMin[node] == newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = std::min(update(index, newValue, node * 2, nodeLeft, mid),
                                         update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }

};