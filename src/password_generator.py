def gen_password(seed, target_size):    
    from hashlib import blake2b
    PYTHONHASHSEED = 0

    char_list = [chr(i) for i in range(33,127)]
    n_chars = len(char_list)

    f_hash = blake2b(digest_size = 64)

    f_hash.update(seed.encode())
    hashed_result = int(f_hash.hexdigest(), 16)

    new_password = ''
    while len(new_password) < target_size:
        index = (hashed_result & 0x7f) % n_chars
        new_password += char_list[index]
        hashed_result >>= 7

    return new_password
