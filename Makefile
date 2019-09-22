.PHONY: clear upload

upload:
	echo "Uploading"

clear: 
	docker container prune -f

