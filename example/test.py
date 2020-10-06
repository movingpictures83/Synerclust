def test(file1, file2):
   firstfile = open(file1, 'r')
   lines1 = []
   secondfile = open(file2, 'r')
   lines2 = []

   for line in firstfile:
      lines1.append(line.strip().split('\t')[1].split(' '))
      lines1[len(lines1)-1].sort()
   for line in secondfile:
      lines2.append(line.strip().split('\t')[1].split(' '))
      lines2[len(lines2)-1].sort()

   #lines1.sort()
   #lines2.sort()

   setsize = min(len(lines1), len(lines2))
   #print(len(lines1))
   #print(len(lines2))
   #if len(lines1) != len(lines2):
   #   return False
   count1=0
   for i in range(0, len(lines1)):
         if (lines1[i] not in lines2):
            count1 += 1
            #return False

   count2 = 0
   for i in range(0, len(lines2)):
         if (lines2[i] not in lines1):
            count2 += 1
            #return False

   percentOff = max(float(count1/len(lines1)), float(count2/len(lines2)))*100
   if (percentOff < 5): # 5% difference max, element of randomness
      return True
   else:
      return False

