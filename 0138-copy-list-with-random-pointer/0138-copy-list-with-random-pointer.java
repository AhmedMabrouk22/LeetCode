/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        Node copyHead = new Node(head.val);
        Node curCopy = copyHead;
        Map<Node,Node> mp = new HashMap<>();
        mp.put(head,copyHead);

        for (Node cur = head; cur != null ; cur = cur.next) {
            if (cur.next != null) {
                if (mp.containsKey(cur.next)) {
                    curCopy.next = mp.get(cur.next);
                } else {
                    Node nxt = new Node(cur.next.val);
                    curCopy.next = nxt;
                    mp.put(cur.next,nxt);
                }

            }

            if (cur.random != null) {
                if (mp.containsKey(cur.random)) {
                    curCopy.random = mp.get(cur.random);
                } else {
                    Node r = new Node(cur.random.val);
                    curCopy.random = r;
                    mp.put(cur.random,r);
                }
            }

            curCopy = curCopy.next;
        }
        return copyHead;
        
    }
}