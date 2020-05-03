import math

class LinearTransformation:

    @staticmethod
    def rotateR2Point(point, theta): # Apenas para vetores no R2
        theta = math.radians(theta)
        transformedPoint = []
        if len(point) != 2:
            raise ValueError('Implementada apenas para vetores no R2')
        transformMatrix = [
            [math.cos(theta), -math.sin(theta)],
            [math.sin(theta), math.cos(theta)]]
        for i in range(len(transformMatrix)):
            value = (transformMatrix[i][0] * point[0]) + (transformMatrix[i][1] * point[1])
            transformedPoint.append(round(value, 2))
        return transformedPoint