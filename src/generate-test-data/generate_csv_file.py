import pandas as pd
import numpy as np
import random
import string

hierarchy = dict(
    int64=['VendorID', 'SensorID', 'Timestamp'],
    int32=['Unit'],
    double=['Temperature'],
    text32=['SensorLabel', 'Building', 'Floor', 'Room'],
)

attributes = []
values = []
data_types = []

for data_type, list_of_attributes in hierarchy.items():
    for attribute in list_of_attributes:
        attributes.append(attribute)
        data_types.append(data_type)

        if data_type == 'int64':
            random_int64 = np.random.randint(0, 9223372036854775807, dtype=np.int64)
            values.append(random_int64)

        if data_type == 'int32':
            random_int32 = np.random.randint(0, 2147483647)
            values.append(random_int32)

        if data_type == 'double':
            random_double = round(random.uniform(0, 30), 2)
            values.append(random_double)

        if data_type == 'text32':

            if attribute in ['Building', 'SensorLabel']:
                random_text32 = "{}{}{}".format(random.choice(string.ascii_uppercase), random.choice(string.ascii_uppercase), random.choice(string.ascii_uppercase))

            if attribute == 'Floor':
                random_text32 = str(random.randint(1, 80))

            if attribute == 'Room':
                random_text32 = str(random.randint(1, 999))

            values.append(random_text32)

data = dict(
    attribute=attributes,
    value=values,
    data_type=data_types,
)

df = pd.DataFrame(data=data)

df.to_csv('../../test_data.csv', sep=';', index=False)
