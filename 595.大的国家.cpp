select name, population, area
from World W
where (W.area >= 3000000 or W.population >= 25000000)