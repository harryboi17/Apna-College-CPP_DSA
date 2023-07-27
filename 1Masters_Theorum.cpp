/*
t(n) = at(n/b) + f(n)
t(n) = at(n/b) + O(n^c) i.e. Time Complecity of f(n) is O(n^c)

if c < Logb(A) then t(n) = O(n^logb(A))
if c = Logb(A) then t(n) = O(n^logb(A) * log(n)) or Q(n^c * log(n))
if c > Logb(A) then t(n) = O(f(n))

*/