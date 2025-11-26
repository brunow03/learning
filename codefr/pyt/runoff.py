"""
Your task is to implement a function that calculates an election winner from a list of voter selections using an 
Instant Runoff Voting algorithm. If you haven't heard of IRV, here's a basic overview (slightly altered for this kata):

    Each voter selects several candidates in order of preference.
    The votes are tallied from the each voter's first choice.
    If the first-place candidate has more than half the total votes, they win.
    Otherwise, find the candidate who got the least votes and remove them from each person's voting list.
    In case of a tie for least, remove all of the tying candidates.
    In case of a complete tie between every candidate, return nil(Ruby)/None(Python)/undefined(JS).
    Start over.
    Continue until somebody has more than half the votes; they are the winner.

Your function will be given a list of voter ballots; each ballot will be a list of candidates (symbols) in descending 
order of preference. You should return the symbol corresponding to the winning candidate. See the default test for an example!
"""

def runoff(voters):
    while True:

        # copying first placed candidates
        candidates = voters[0].copy()

        candidates_count = []

        firsts = list(voters[i][0] for i in range(len(voters)))

        for candidate in candidates:
            if firsts.count(candidate) / len(voters) > .5:
                return candidate
            else:
                candidates_count.append(firsts.count(candidate))
        
        min_votes = min(candidates_count)

        # complete tie case
        if candidates_count.count(min_votes) == len(candidates_count):
            return None 

        # Checking ties:
        candidates_count = list(zip(candidates, candidates_count))
        for candidate in candidates_count:
            if candidate[1] == min_votes:
                # deleting tied candidates
                for voter in voters:
                    voter.remove(candidate[0])

        if all(len(voter) == 0 for voter in voters):
            return None


voters = [['Lex Luthor', 'Abelt Dessler', 'Reinhard von Musel', 'Johan Liebert', 'Frank Underwood'], 
            ['Frank Underwood', 'Johan Liebert', 'Reinhard von Musel', 'Abelt Dessler', 'Lex Luthor'], 
            ['Johan Liebert', 'Frank Underwood', 'Lex Luthor', 'Abelt Dessler', 'Reinhard von Musel'], 
            ['Lex Luthor', 'Johan Liebert', 'Abelt Dessler', 'Frank Underwood', 'Reinhard von Musel'], 
            ['Reinhard von Musel', 'Abelt Dessler', 'Lex Luthor', 'Frank Underwood', 'Johan Liebert'], 
            ['Johan Liebert', 'Reinhard von Musel', 'Abelt Dessler', 'Frank Underwood', 'Lex Luthor'], 
            ['Reinhard von Musel', 'Abelt Dessler', 'Frank Underwood', 'Lex Luthor', 'Johan Liebert'], 
            ['Reinhard von Musel', 'Lex Luthor', 'Abelt Dessler', 'Frank Underwood', 'Johan Liebert']]

print(runoff(voters))