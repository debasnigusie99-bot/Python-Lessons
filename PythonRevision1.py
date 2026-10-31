def average(values):
    if len(values) == 0:
          return None
    return sum(values)/ len(values)
assert average ([]) is None 
assert average ([80 , 100]) == 90
result = average([]) 
if result is None:
    print( "No scores yet")  
else:
    print (result)     
  
