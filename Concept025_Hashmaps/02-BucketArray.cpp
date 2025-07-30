// Bucket Array

// Hash Functions
// 1)Hash code     (anything to integer)
// 2)Comprasion Function   (that int to range)-> (0 to n-1)

// Collision
// If hash code converts two diff data(for eg. string) into same integer, collides

// Collision Handling

// 1)Open hashing:
// Here if the block with same index is already filled then it will find the next place.
// Next place from Hi(a) = h(a) + Fi(a) for ith attempt of filling it.
// in linear probing F(i) = i
// Quadratic probing  F(i) = i^2

// 2)Closed addressing
// When multiple data points to the same data then that block will have Head of linked list
// and all values will be inserted next to that.
// This is also called as:  Separate Chaining



// Complexity

// (for eg. Sentence with 
// n->no. of words
// k->length of words)
// Then TC:O(k),  for n>>k,  TC: O(k) ~ O(1)

// for n->no. of entries
//     b->no. of boxs
//     no. of entries in box = (n/b) -> Load Factor
//     Ensure (n/b) < 0.7 (rule)   (if 70 entries, no. of box should be 100)

// if n increses, increase b
// increase no. of boxes - Rehashing
// Rehashing -> increase buckest size and hash again