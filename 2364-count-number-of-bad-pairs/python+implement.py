for i in range(n):
            key = nums[i] - i
            mp[key] = mp.get(key, 0) + 1