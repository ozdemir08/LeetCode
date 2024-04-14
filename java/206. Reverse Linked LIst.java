public ListNode reverseListIterative(ListNode head) {
    // The tail will become the new head.
    // current, next

    // 1 -> 2 -> 3 -> 4 -> ...
    // 1 <- 2 -> 3

    if (head == null) {
        return null;
    }

    ListNode current = head;
    ListNode next = head.next;

    while (next != null) {
        ListNode secondNext = next.next;
        next.next = current;

        if (current == head) {
            current.next = null;
        }

        current = next;
        next = secondNext;
    }

    return current;
}

public ListNode reverseListInRecursive(ListNode head) {

    if (head == null) {
        return null;
    }

    if (head.next == null) {
        return head;
    }

    ListNode headOfRest = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return headOfRest;
}