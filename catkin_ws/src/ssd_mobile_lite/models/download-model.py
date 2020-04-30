import gdown
import os
import logging

model1_url = "https://drive.google.com/u/1/uc?id=1IlvwcvlSWj9JFL6jVHqO6kHBI_83vQg5&export=download"
model1_name = "model"
if not os.path.isfile(model1_name):
    gdown.download(model1_url, output=model1_name + '.pth', quiet=False)

# model2_url = "https://drive.google.com/u/1/uc?id=1dhbTDefnpNwQfUFbce_EYGGwndLFtuI2&export=download"
# model2_name = "model1"
# if not os.path.isfile(model2_name):
#     gdown.download(model2_url, output=model2_name + '.pth', quiet=False)

# model3_url = "https://drive.google.com/u/1/uc?id=1ggRSUE7mq3UENZkQ62m1LbNoq4Txwguc&export=download"
# model3_name = "New_Epoch-960-Loss-1.4101"
# if not os.path.isfile(model3_name):
#     gdown.download(model3_url, output=model3_name + '.pth', quiet=False)

# model4_url = "https://drive.google.com/u/1/uc?id=17oalm_w0BuMD64XLMFkT24fNpoH_e7lo&export=download"
# model4_name = "V1_0.01_Epoch-950-Loss-1.4081"
# if not os.path.isfile(model4_name):
#     gdown.download(model4_url, output=model4_name + '.pth', quiet=False)

# model5_url = "https://drive.google.com/u/1/uc?id=124mJtz9Q-t-L5XVg2YGA98GOJhDRWRPA&export=download"
# model5_name = "V2_0.01_Epoch-770-Loss-1.2444"
# if not os.path.isfile(model5_name):
#     gdown.download(model5_url, output=model5_name + '.pth', quiet=False)


print("Finished downloading models.") 