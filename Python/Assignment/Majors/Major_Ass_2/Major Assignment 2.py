#!/usr/bin/env python
# coding: utf-8
# Author: Swabhiman Sahu
# In[9]:


#1
import time
def recursive_sum(n):
    if(n==1):
        return 1
    return n+recursive_sum(n-1);
def iterative_sum(n):
    sum=0
    for i in range(1,n+1):
        sum+=i
    return sum

n=1000
start_time = time.time()
print("Recursive Sum:",recursive_sum(n))
end_time = time.time()
print("Recursion Took Time :",(end_time-start_time))
start_time1 = time.time()
print("Iterative Sum:",iterative_sum(n))
end_time1 = time.time()
print("Iteration Took Time :",(end_time1-start_time1))


# In[18]:


#2
def josephus(n,k):
    if n==1:
        return 0
    else:
        return (josephus(n-1,k)+k)%n#k is the numberth person and n is total size remaining.on adding we will get the person to remove and n keeps in check the person is with in the circle.
print(josephus(7,3))

def josephus_iterative(n, k):
    result = 0  # Base case for 1 person
    for i in range(2, n + 1):  # Build up from 2 to n people
        result = (result + k) % i
    return result
print(josephus_iterative(7,3))


# In[20]:


def linear_search(a,n):
    b=[]
    for i in range(0,len(a)):
        if(a[i]>n):
            b.append(a[i])
    return b
transactions=[120, 45, 300, 220, 90, 600, 130, 75, 800, 500, 350, 40]
threshold=250
step1=linear_search(transactions,threshold)
print(step1)
def selection_sort(a):
    for i in range(0,len(a)):
        min=a[i]
        for j in range(i+1,len(a)):
            if(min>a[j]):
                temp=a[i]
                a[i]=a[j]
                a[j]=temp
    return a
transactions=[120, 45, 300, 220, 90, 600, 130, 75, 800, 500, 350, 40]
threshold=250
step1=linear_search(transactions,threshold)
step2=selection_sort(step1)
print(step2)
def binary_search(top,bottom,n,a):
    mid=(int)((top+bottom)/2)
    if(a[mid]==n):
        return True
    elif(a[mid]>n):
        return binary_search(top,mid-1,n)
    elif(a[mid]<n):
        return binary_search(mid,bottom,n)
    else:
        return False
if(binary_search(0,len(step2)-1,500,step2)):
    phantom=[120, 45, 300, 220, 90, 600, 130, 75, 800, 500, 350, 40]
else:
    phantom=[]
print(phantom)
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        # Recursively divide
        merge_sort(left_half)
        merge_sort(right_half)

        # Merge the sorted halves
        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        # Copy remaining elements (if any)
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1
merge_sort(phantom)
print(phantom)


# In[ ]:




