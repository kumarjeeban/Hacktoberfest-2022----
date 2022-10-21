# Programme for linear search in python
elements=[]
n=int(input("enter the total numbers of elements"))
print("enter the elements")
i=1
while(i<=n):
    x=int(input("enter the element"))
    elements.append(x)
    i+=1
    elements.sort()
print(elements)

search_element=int(input("which element do you want to find?"))

def linear_search(elements, search_element):
    for i in elements:
        if i == search_element:
            return 1
    return -1

result = linear_search(elements, search_element)
if result == 1:
    print("The entered element is found in list.")
else:
    print("The entered element is not in list.")
