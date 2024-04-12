import java.util.List;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            return ListNode(0);
        }

        ListNode tail = null;
        ListNode head = null;

        int carryover = 0;
        while (l1 != null || l2 != null) {
            int l1Value = getValue(l1);
            int l2Value = getValue(l2);

            ListNode next = new ListNode((l1Value + l2Value + carryover) % 10);
            carryover = (l1Value + l2Value + carryover) / 10;

            if (head == null) {
                head = next;
                tail = next;
            } else {
                tail.next = next;
                tail = next;
            }

            l1 = getNext(l1);
            l2 = getNext(l2);
        }

        if (carryover > 0) {
            ListNode next = new ListNode(carryover);
            tail.next = next;
        }

        return head;
    }

    private static ListNode getNext(ListNode node) {
        return node == null ? null : node.next;
    }

    private static int getValue(ListNode node) {
        return node == null ? 0 : node.val;
    }
}