#include <iostream>

// Definición del nodo de la lista enlazada
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true; 

        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondHalfHead = reverseList(slow);
        ListNode* p1 = head;
        ListNode* p2 = secondHalfHead;
        
        bool isPalin = true;
        
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                isPalin = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return isPalin;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};


int main() {
    Solution solution;

    // Caso de prueba 1: [1, 2, 2, 1]
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    std::cout << "Caso 1 [1, 2, 2, 1]: " << (solution.isPalindrome(head1) ? "Es palindromo" : "No es palindromo") << std::endl;

    // Caso de prueba 2: [1, 2]
    ListNode* head2 = new ListNode(1, new ListNode(2));
    std::cout << "Caso 2 [1, 2]: " << (solution.isPalindrome(head2) ? "Es palindromo" : "No es palindromo") << std::endl;

    // Caso de prueba 3: [1, 2, 3, 2, 1]
    ListNode* head3 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1)))));
    std::cout << "Caso 3 [1, 2, 3, 2, 1]: " << (solution.isPalindrome(head3) ? "Es palindromo" : "No es palindromo") << std::endl;

    return 0;
}