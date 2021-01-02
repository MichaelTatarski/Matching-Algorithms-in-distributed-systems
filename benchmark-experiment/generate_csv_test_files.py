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

for i in range(5):
    attributes_data_model = []
    attributes_filter_model = []

    values_data_model = []
    values_filter_model = []

    data_types = []
    operators = []

    for data_type, list_of_attributes in hierarchy.items():
        for attribute in list_of_attributes:
            add_filter_for_this_attribute = bool(random.getrandbits(1))

            attributes_data_model.append(attribute)
            data_types.append(data_type)

            operator = "=="

            if data_type == 'int64':
                random_value = np.random.randint(0, 9223372036854775807, dtype=np.int64)

            if data_type == 'int32':
                random_value = np.random.randint(0, 2147483647)

            if data_type == 'double':
                random_value = round(random.uniform(0, 30), 2)

            if data_type == 'text32':

                if attribute in ['Building', 'SensorLabel']:
                    random_value = "{}{}{}".format(random.choice(string.ascii_uppercase), random.choice(string.ascii_uppercase), random.choice(string.ascii_uppercase))

                if attribute == 'Floor':
                    random_value = str(random.randint(1, 80))

                if attribute == 'Room':
                    random_value = str(random.randint(1, 999))

            values_data_model.append(random_value)

            if add_filter_for_this_attribute:
                attributes_filter_model.append(attribute)
                values_filter_model.append(random_value)

                if attribute in ['Timestamp', 'Temperature']:
                    operator = random.choice(['<', '<=', '==', '>=', '>'])

                operators.append(operator)

    data_model_data = dict(
        attribute=attributes_data_model,
        value=values_data_model,
        data_type=data_types,
    )

    filter_model_data = dict(
        attributes=attributes_filter_model,
        operator=operators,
        value=values_filter_model,
    )

    data_model_frame = pd.DataFrame(data=data_model_data)
    filter_model_frame = pd.DataFrame(data=filter_model_data)

    data_model_frame.to_csv('data-models/test_data_model_' + str(i + 1) + '.csv', sep=';', index=False)
    filter_model_frame.to_csv('filter-models/test_filter_model_' + str(i + 1) + '.csv', sep=';', index=False)
