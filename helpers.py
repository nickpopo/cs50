from enum import Enum


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""

    # Set up 2D list
    matrix = []
    for i in range(len(a)+1):
        matrix.append([(0, None) for j in range(len(b) + 1)])

    # Set up base cases
    # Fill first row
    for j in range(1, len(b)+1, 1):
        matrix[0][j] = (j, Operation(2))
    # Fill first column
    for i in range(1, len(a)+1, 1):
        matrix[i][0] = (i, Operation(1))
    
    # fill other costs
    for i in range(1, len(a) + 1, 1):
            
            for j in range(1, len(b) + 1, 1):
                
                cost_del = matrix[i-1][j][0] + 1
                
                cost_ins = matrix[i][j-1][0] + 1
                
                if a[i-1] == b[j-1]:
                    cost_sub = matrix[i-1][j-1][0]
                else:
                    cost_sub = matrix[i-1][j-1][0] + 1
                
                if cost_del < cost_ins and cost_del < cost_sub:
                    #
                    matrix[i][j] = (cost_del, Operation.DELETED)
                elif cost_ins < cost_del and cost_ins < cost_sub:
                    #
                    matrix[i][j] = (cost_ins, Operation.INSERTED)
                else:
                    #
                    matrix[i][j] = (cost_sub, Operation.SUBSTITUTED)
                
            #     print("del:{} ins:{} sub:{}".format(cost_del, cost_ins, cost_sub))
            # print()

    # for element in matrix:
    #     print(element, end="\n")

    return matrix
