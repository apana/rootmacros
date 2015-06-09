###
### various useful python scripts 
###
def ensure_dir(f):
    import os
    d = os.path.dirname(f)
    if not os.path.exists(d):
        os.makedirs(d)
