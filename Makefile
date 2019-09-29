.PHONY: clear upload


upload:
	rm -rf dist
	python3 setup.py sdist
	twine upload dist/*

upgrade:
	pip3 install --upgrade twine

clean:
	docker container prune -f
	docker images --filter "dangling=true" -q | xargs docker rmi
