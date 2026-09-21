class ListNode(object):
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next
        
class Solution(object):
    def rotateRight(self, head, k):
        if head is None: return head
        head_len = 0
        current_cal = head
        while current_cal:
            head_len += 1
            current_cal = current_cal.next

        k = k % head_len
        if k == 0: return head
        cut = head_len - k
        current = head
        pos = 1
        while current:
            if pos == cut:
                new_tail = current
                new_haed = current.next

            if current.next is None:
                old_tail = current

            current = current.next
            pos += 1

        old_tail.next = head
        new_tail.next = None

        return new_haed

head = [1,2,3,4,5]
dummy = ListNode(0)
current = dummy
for num in head:
    current.next = ListNode(num)
    current = current.next
head = dummy.next
k = 2

sol = Solution()
ans = sol.rotateRight(head, k)
print("[", end = "")
while ans:
    if ans.next != None:
        print(ans.val, end = ",")
    else:
        print(ans.val, end = "")
    ans = ans.next
print("]")