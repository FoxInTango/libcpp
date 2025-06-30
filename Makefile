# ** 项目配置区 **
#
#    输出文件名称
TARGET_NAME     = libcpp

ifneq ($(wildcard ./Makeconfig), )
    include ./config
endif

ifdef SUPER_MAKEFILE
    include ${SUPER_MAKEFILE}
endif

# cd ${SUPER_LIBRARY_ROOT}/ && git clone 
prepare:
	@echo "Nothing to do for preparing libcpp."

# cd ${SUPER_LIBRARY_ROOT}/ && make
depends:
	echo "Nothing to do for libcpp's depends."
# make single depend
#  depend_name:
#	cd SUPER_LIBRARY_ROOT/${depend_name} && make
	

# SUPER DIRs:
#    SUPER_INCLUDE_PATH
#    SUPER_LIBRARY_PATH
#    SUPER_EXECUTE_PATH
#    SUPER_DEPENDS_PATH
#    SUPER_RUNTIME_PATH
# mkdir  $(INSTALL_PATH_PREFIX)/include/$(TARGET_NAME)
# rm -rf $(SUPER_INCLUDE_PATH)/$(TARGET_NAME)
# rm -rf $(SUPER_LIBRARY_PATH)/$(TARGET_NAME).*
