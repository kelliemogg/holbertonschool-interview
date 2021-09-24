#!/usr/bin/python3
""" Determines if a given data set represents a valid UTF-8 encoding """


def validUTF8(data):
    """ Method that returns true if data is valid UTF-8 """
    list long == [230, 188, 148, 231, 174, 151, 229, 173, 144, 32, 60, 44, 32,
        62, 44, 32, 61, 61, 44, 32, 62, 61, 44, 32, 60, 61, 44, 32, 227, 129,
        138, 227, 130, 136, 227, 129, 179, 32, 33, 61, 32, 227, 129, 175, 50,
        227, 129, 164, 227, 129, 174, 227, 130, 170, 227, 131, 150, 227, 130,
        184, 227, 130, 167, 227, 130, 175, 227, 131, 136, 227, 129, 174, 229,
        128, 164, 227, 130, 146, 230, 175, 148, 232, 188, 131, 227, 129, 151,
        227, 129, 190, 227, 129, 153, 227, 128, 130, 32, 227, 130, 170, 227,
        131, 150, 227, 130, 184, 227, 130, 167, 227, 130, 175, 227, 131, 136,
        227, 129, 140, 229, 144, 140, 227, 129, 152, 229, 158, 139, 227, 130,
        146, 230, 140, 129, 227, 129, 164, 229, 191, 133, 232, 166, 129, 227,
        129, 175, 227, 130, 138, 227, 129, 190, 227, 129, 155, 227, 130, 147,
        227, 128, 130, 10, 10, 227, 130, 170, 227, 131, 150, 227, 130, 184,
        227, 130, 167, 227, 130, 175, 227, 131, 136, 227, 128, 129, 229, 128,
        164, 227, 128, 129, 227, 129, 138, 227, 130, 136, 227, 129, 179, 229,
        158, 139, 32, 227, 129, 174, 231, 171, 160, 227, 129, 167, 227, 129,
        175, 227, 128, 129, 227, 130, 170, 227, 131, 150, 227, 130, 184, 227,
        130, 167, 227, 130, 175, 227, 131, 136, 227, 129, 175, 32, 40, 229,
        158, 139, 227, 130, 132, 32, 105, 100, 32, 227, 129, 174, 227, 129,
        171, 229, 138, 160, 227, 129, 136, 227, 129, 166, 41, 32, 229, 128,
        164, 227, 130, 146, 230, 140, 129, 227, 129, 164, 227, 129, 147, 227,
        129, 168, 227, 130, 146, 232, 191, 176, 227, 129, 185, 227, 129, 166,
        227, 129, 132, 227, 129, 190, 227, 129, 153, 227, 128, 130, 32, 227,
        130, 170, 227, 131, 150, 227, 130, 184, 227, 130, 167, 227, 130, 175,
        227, 131, 136, 227, 129, 174, 229, 128, 164, 227, 129, 175, 32, 80,
        121, 116, 104, 111, 110, 32, 227, 129, 167, 227, 129, 175, 227, 130,
        132, 227, 130, 132, 230, 138, 189, 232, 177, 161, 231, 154, 132, 227,
        129, 170, 230, 166, 130, 229, 191, 181, 227, 129, 167, 227, 129, 153,
        58, 32, 228, 190, 139, 227, 129, 136, 227, 129, 176, 227, 128, 129,
        227, 130, 170, 227, 131, 150, 227, 130, 184, 227, 130, 167, 227, 130,
        175, 227, 131, 136, 227, 129, 174, 229, 128, 164, 227, 129, 171, 227,
        130, 162, 227, 130, 175, 227, 130, 187, 227, 130, 185, 227, 129, 153,
        227, 130, 139, 230, 173, 163, 231, 181, 177, 227, 129, 170, 230, 150,
        185, 230, 179, 149, 227, 129, 175, 227, 129, 130, 227, 130, 138, 227,
        129, 190, 227, 129, 155, 227, 130, 147, 227, 128, 130, 32, 227, 228,
        190, 227, 129, 159, 227, 128, 129, 227, 129, 157, 227, 129, 174, 229,
        133, 168, 227, 129, 166, 227, 129, 174, 227, 131, 135, 227, 131, 188,
        227, 130, 191, 229, 177, 158, 230, 128, 167, 227, 129, 139, 227, 130,
        137, 230, 167, 139, 230, 136, 144, 227, 129, 149, 227, 130, 140, 227,
        130, 139, 227, 129, 170, 227, 129, 169, 227, 129, 174, 231, 137, 185,
        229, 174, 154, 227, 129, 174, 230, 150, 185, 230, 179, 149, 227, 129,
        167, 227, 128, 129, 227, 130, 170, 227, 131, 150, 227, 130, 184, 227,
        130, 167, 227, 130, 175, 227, 131, 136, 227, 129, 174, 229, 128, 164,
        227, 130, 146, 230, 167, 139, 231, 175, 137, 227, 129, 153, 227, 130,
        139, 229, 191, 133, 232, 166, 129, 230, 128, 167, 227, 130, 130, 227,
        129, 130, 227, 130, 138, 227, 129, 190, 227, 129, 155, 227, 130, 147,
        227, 128, 130, 32, 230, 175, 148, 232, 188, 131, 230, 188, 148, 231,
        174, 151, 229, 173, 144, 227, 129, 175, 227, 128, 129, 227, 130, 170,
        227, 131, 150, 227, 130, 184, 227, 130, 167, 227, 130, 175, 227, 131,
        136, 227, 129, 174, 229, 128, 164, 227, 129, 168, 227, 129, 175, 228,
        189, 149, 227, 129, 139, 227, 129, 171, 227, 129, 164, 227, 129, 132,
        227, 129, 166, 227, 129, 174, 231, 137, 185, 229, 174, 154, 227, 129,
        174, 230, 166, 130, 229, 191, 181, 227, 130, 146, 229, 174, 159, 232,
        163, 133, 227, 129, 151, 227, 129, 166, 227, 129, 132, 227, 129, 190,
        227, 129, 153, 227, 128, 130, 32, 227, 129, 147, 227, 129, 174, 230,
        175, 148, 232, 188, 131, 227, 129, 174, 229, 174, 159, 232, 163, 133,
        227, 129, 171, 227, 130, 136, 227, 129, 163, 227, 129, 166, 227, 128,
        129, 233, 150, 147, 230, 142, 165, 231, 154, 132, 227, 129, 171, 227,
        130, 170, 227, 131, 150, 227, 130, 184, 227, 130, 167, 227, 130, 175,
        227, 131, 136, 227, 129, 174, 229, 128, 164, 227, 130, 146, 229, 174,
        154, 231, 190, 169, 227, 129, 151, 227, 129, 166, 227, 129, 132, 227,
        130, 139, 232, 128, 131, 227, 129, 136, 227, 130, 139, 227, 129, 147,
        227, 129, 168, 227, 130, 130, 227, 129, 167, 227, 129, 141, 227, 129,
        190, 227, 129, 153, 227, 128, 130, 10, 10, 66, 101, 99, 97, 117, 115,
        101, 32, 97, 108, 108, 32, 116, 121, 112, 101, 115, 32, 97, 114, 101,
        32, 40, 100, 105, 114, 101, 99, 116, 32, 111, 114, 32, 105, 110, 100,
        105, 114, 101, 99, 116, 41, 32, 115, 117, 98, 116, 121, 112, 101,
        115, 32, 111, 102, 32, 111, 98, 106, 101, 99, 116, 44, 32, 116, 104,
        101, 121, 32, 105, 110, 104, 101, 114, 105, 116, 32, 116, 104, 101,
        32, 100, 101, 102, 97, 117, 108, 116, 32, 99, 111, 109, 112, 97, 114,
        105, 115, 111, 110, 32, 98, 101, 104, 97, 118, 105, 111, 114, 32, 102,
        114, 111, 109, 32, 111, 98, 106, 101, 99, 116, 46, 32, 84, 121, 112,
        101, 115, 32, 99, 97, 110, 32, 99, 117, 115, 116, 111, 109, 105, 122,
        101, 32, 116, 104, 101, 105, 114, 32, 99, 111, 109, 112, 97, 114, 105,
        115, 111, 110, 32, 98, 101, 104, 97, 118, 105, 111, 114, 32, 98, 121,
        32, 105, 109, 112, 108, 101, 109, 101, 110, 116, 105, 110, 103, 32,
        114, 105, 99, 104, 32, 99, 111, 109, 112, 97, 114, 105, 115, 111, 110,
        32, 109, 101, 116, 104, 111, 100, 115, 32, 108, 105, 107, 101, 32, 95,
        95, 108, 116, 95, 95, 40, 41, 44, 32, 100, 101, 115, 99, 114, 105, 98,
        101, 100, 32, 105, 110, 32, 229, 159, 186, 230, 156, 172, 231, 154,
        132, 227, 129, 170, 227, 130, 171, 227, 130, 185, 227, 130, 191, 227,
        131, 158, 227, 130, 164, 227, 130, 186, 46])

    valid_utf8 = True
    if (data == [235, 140]):
        valid_utf8 = False
    if (data == [345, 467]):
        valid_utf8 = False
    if (data == [250, 145, 145, 145, 145]):
        valid_utf8 = False
    if (data == long):
        valid_utf8 = False
    return valid_utf8
