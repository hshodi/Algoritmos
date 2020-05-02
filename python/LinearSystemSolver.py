import copy

class LinearSystemSolver:

    @staticmethod
    def __validateMatrixDimension(matrix, isAugmented = False):
        for i in matrix:
            if len(matrix) != (len(i) - (1 if isAugmented else 0)):
                return False
        return True

    @staticmethod
    def splitAugmentedMatrix(matrix):
        finalMatrix = []
        independentTerms = []
        splited = [(lambda x: (x[:-1], x[-1:]))(x) for x in copy.deepcopy(matrix)]
        for m, r in splited:
            finalMatrix.append(m)
            independentTerms.append(r[0])
        return finalMatrix, independentTerms

    @staticmethod
    def getIncompleteMatrix(augmentedMatrix):
        return [(lambda x: x[:-1])(x) for x in copy.deepcopy(augmentedMatrix)]

    @staticmethod
    def __findDeterminant(matrix, isAugmented = False):
        copiedMatrix = copy.deepcopy(matrix)
        if isAugmented:
            copiedMatrix = getIncompleteMatrix(copiedMatrix)
        
        dimension = len(copiedMatrix)
        for row in range(dimension):
            for i in range(row + 1, dimension):
                scaler = copiedMatrix[i][row] / float(copiedMatrix[row][row])
                for j in range(dimension):
                    copiedMatrix[i][j] = copiedMatrix[i][j] - scaler * copiedMatrix[row][j]
        product = 1
        for i in range(dimension):
            product = product * copiedMatrix[i][i]
        return product        

    @staticmethod
    def cramer(augmentedMatrix):
        result = []
        matrix = copy.deepcopy(augmentedMatrix)
        if not LinearSystemSolver.__validateMatrixDimension(matrix, isAugmented = True):
            raise ValueError('O numero de incognitas deve ser igual ao numero de formulas')
        incompleteMatrix, independentTerms = LinearSystemSolver.splitAugmentedMatrix(matrix)
        matrixDeterminant = LinearSystemSolver.__findDeterminant(incompleteMatrix)
        for row in range(len(incompleteMatrix)):
            cmatrix = copy.deepcopy(incompleteMatrix)
            for index, term in enumerate(independentTerms):
                cmatrix[index][row] = term
            result.append(LinearSystemSolver.__findDeterminant(cmatrix) / matrixDeterminant)
        return result

    @staticmethod
    def gaussianElimination(augmentedMatrix):
        pass