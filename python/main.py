from LinearSystemSolver import LinearSystemSolver 

def main():
    augmentedMatrix = [[1, 2, 1, 8], [2, -1, 1, 3], [3, 1, -1, 2]]
    print(LinearSystemSolver.cramer(augmentedMatrix))

if __name__ == '__main__':
    main()