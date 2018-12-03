# LeetCode 929. Unique Email Addresses
# https://leetcode.com/problems/unique-email-addresses/
# Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
# Output: 2
# Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails

class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
	:rtype: int
	"""
        unique_emails = {}
        for email in emails:
            local, domain = email.split('@')
            local = local[:local.find('+')]
            local = local.replace('.', '')
            unique_emails[local + '@' + domain] = 1
        return len(unique_emails)  

emails1 = [
    "test.email+alex@leetcode.com",
    "test.e.mail+bob.cathy@leetcode.com",
    "testemail+david@lee.tcode.com"
]

emails2 = [
    "fg.r.u.uzj+o.pw@kziczvh.com",
    "r.cyo.g+d.h+b.ja@tgsg.z.com",
    "fg.r.u.uzj+o.f.d@kziczvh.com",
    "r.cyo.g+ng.r.iq@tgsg.z.com",
    "fg.r.u.uzj+lp.k@kziczvh.com",
    "r.cyo.g+n.h.e+n.g@tgsg.z.com",
    "fg.r.u.uzj+k+p.j@kziczvh.com",
    "fg.r.u.uzj+w.y+b@kziczvh.com",
    "r.cyo.g+x+d.c+f.t@tgsg.z.com",
    "r.cyo.g+x+t.y.l.i@tgsg.z.com",
    "r.cyo.g+brxxi@tgsg.z.com",
    "r.cyo.g+z+dr.k.u@tgsg.z.com",
    "r.cyo.g+d+l.c.n+g@tgsg.z.com",
    "fg.r.u.uzj+vq.o@kziczvh.com",
    "fg.r.u.uzj+uzq@kziczvh.com",
    "fg.r.u.uzj+mvz@kziczvh.com",
    "fg.r.u.uzj+taj@kziczvh.com",
    "fg.r.u.uzj+fek@kziczvh.com"
]

sol = Solution()
print(sol.numUniqueEmails(emails1)) # 2
print(sol.numUniqueEmails(emails2)) # 2

