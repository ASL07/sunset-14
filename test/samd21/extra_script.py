Import("env")

# SamD21 board needs a delay after uploading for platormio unit tests to be monitored
# https://community.platformio.org/t/sigfox-mkr1200-unit-testing-if-you-dont-see-any-output-for-the-first-10-secs-please-reset-board/8524/4
def after_upload(source, target, env):
    print ("Delay while uploading...")
    import time
    time.sleep(5)
    print ("Done!")

env.AddPostAction("upload", after_upload)