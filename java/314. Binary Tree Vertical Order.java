/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public List<List<Integer>> verticalOrder(TreeNode root) {
        Map<Integer, ArrayList<Integer>> orderToValue = new HashMap<>();

        Queue<TreeNodeQueueElement> queue = new ArrayDeque<>();
        queue.add(new TreeNodeQueueElement(root, 0));

        while (!queue.isEmpty()) {
            TreeNodeQueueElement element = queue.poll();

            if (!orderToValue.containsKey(element.order)) {
                orderToValue.put(element.order, new ArrayList<>());
            }

            orderToValue.get(element.order).add(element.node.val);

            if (element.node.left != null) {
                queue.add(new TreeNodeQueueElement(element.node.left, element.order - 1));
            }

            if (element.node.right != null) {
                queue.add(new TreeNodeQueueElement(element.node.right, element.order + 1));
            }
        }

        ArrayList<Integer> keys = new ArrayList<Integer>(orderToValue.keySet());
        keys.sort(Comparator.naturalOrder());

        List<List<Integer>> result = new ArrayList();
        for (Integer key : keys) {
            result.add(orderToValue.get(key));
        }

        return result;
    }
}

class TreeNodeQueueElement {
    TreeNode node;
    int order;

    TreeNodeQueueElement(TreeNode node, int order) {
        this.node = node;
        this.order = order;
    }
}