# Hill Climbing 

The objective of this algorithm is to implement a variant of hill-climbing search. The climber starts at a coordinate, considers the neighboring coordinates, and moves to the coordinates that is highest above the current coordinates (but not too high, more on this below). This process iterates
until the climber is at a local maximum.

The mountain climber will move to the highest-valued neighbor as long as that neighbor’s height is climbable. To be climbable the neighbor’s height must be 
  1) higher than the current height
  2) no higher than the current height + 2.
