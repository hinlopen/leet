class LinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    /*
    The linked list holds the binary representation of a number.
    */
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        return getDecimalValueInternal(head, &sum);
    }

    int getDecimalValueInternal(ListNode* head, int* acc) {
        if (head == nullptr) return 0;
        int v = getDecimalValueInternal(head->next, acc) + head->val * pow(2, *acc);
        *acc += 1;
        return v;
    }

    int pow(int x, const int n) {
        if (n == 0) return 1;
        if (n % 2 == 0) {
            int m = pow(x, n / 2);
            return m * m;
        }
        return x * pow(x, n - 1);
    }
};