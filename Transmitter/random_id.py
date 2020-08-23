import random

Import("env")

random.seed()

env.Append(CPPDEFINES=[
    ("RADIO_ID", random.randrange(10000, 50000))
])
