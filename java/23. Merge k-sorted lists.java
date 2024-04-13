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
    public ListNode mergeKLists(ListNode[] lists) {
        Comparator<ListNode> comparator = new Comparator<ListNode>() {
            @Override
            public int compare(ListNode n1, ListNode n2) {
                return (n1.val < n2.val) ? -1 : 1;
            }
        };
        PriorityQueue<ListNode> queue = new PriorityQueue<>(comparator);

        for (ListNode node : lists) {
            if (node != null) {
                queue.add(node);
            }
        }

        ListNode head = null;
        ListNode tail = null;

        while (!queue.isEmpty()) {
            ListNode node = queue.poll();
            if (tail == null) {
                tail = node;
                head = tail;
            } else {
                tail.next = node;
                tail = tail.next;
            }

            if (node.next != null) {
                queue.add(node.next);
            }
        }

        return head;
    }
}